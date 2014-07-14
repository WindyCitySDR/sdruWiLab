function result = testPHYReceive(decimation)

result = 100;

[...
    ObjAGC,...           %Objects
    ObjSDRuReceiver,...
    ObjDetect,...
    ObjPreambleDemod,...
    ObjDataDemod,...
    estimate,...         %Structs
    rx,...
    timeoutDuration,...  %Values/Vectors
    messageBits...
    ] = CreateTXRX;

ObjSDRuReceiver.DecimationFactor = double(decimation);
% Adjust offset for node
%ObjSDRuReceiver.CenterFrequency = rx.CenterFrequency - offset;

fprintf('Starting Receiver Loop\n');

while true
[recoveredMessage] = PHYReceive(...
                ObjAGC,...           %Objects
                ObjSDRuReceiver,...
                ObjDetect,...
                ObjPreambleDemod,...
                ObjDataDemod,...
                estimate,...         %Structs
                rx,...
                timeoutDuration,...  %Values/Vectors
                messageBits...
                );

            
            if ~strcmp(recoveredMessage,'CRC Error') && ~strcmp(recoveredMessage,'Timeout') 
                fprintf('Got Message: %s\n',recoveredMessage);
            end
end

fprintf('Finished Receiver Loop\n');


end