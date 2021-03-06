function testMACTransmitter(offsets, nodeNum)



[...
    ObjAGC,...           %Objects
    ObjSDRuReceiver,...
    ObjSDRuTransmitter,...
    ObjDetect,...
    ObjPreambleDemod,...
    ObjDataDemod,...
    estimate,...         %Structs
    tx,...
    timeoutDuration,...  %Values/Vectors
    messageBits...
    ] = CreateTXRX;

tx.offsetTable = offsets;
tx.nodeNum = nodeNum;


ObjSDRuTransmitter.CenterFrequency = ObjSDRuTransmitter.CenterFrequency + 1e6;

% Previous Message string holder
coder.varsize('previousMessage', [1, 80], [0 1]);
previousMessage = '';

correct = 0; %Keep track of successful messages

for run = 1 : 1e4
    %message = ['Random Message',char(96+run)];%Create different messages each times
    message = ['Random Message'];%Dont create different messages each times
    
    % Who should get the message?
    recipient = 2;
    
    [previousMessage, msgStatus] = MACLayerTransmitter(...
        ObjAGC,...           %Objects
        ObjSDRuReceiver,...
        ObjSDRuTransmitter,...
        ObjDetect,...
        ObjPreambleDemod,...
        ObjDataDemod,...
        estimate,...         %Structs
        tx,...
        timeoutDuration,...  %Values/Vectors
        messageBits,...
        message,...
        previousMessage,...
        recipient...
        );
    
    %Wait some time
    waitTime = 0.2e2; % Calculated in seconds buts thats far from realistic 
    fprintf('TOP| DONE Iteration: Waiting some time between actions\n');
    if msgStatus
        correct = correct + 1;
        fprintf('Successful Transmissions: %d of %d\n',int32(correct),int16(run));
    end
    Wait(ObjSDRuReceiver,tx.samplingFreq,waitTime);
    
    
end


end
