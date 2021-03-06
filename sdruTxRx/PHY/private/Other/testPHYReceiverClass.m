%function testPHYReceiverClass
inputPayloadMessage = 'HelloDave';
samplingFreq = 5e6;


[~,hPreambleDemod, dataToTx, tx ] = generateOFDMSignal_TX2(inputPayloadMessage,samplingFreq, 1, 1);% 30 Dupe frames created (NOTE! author shouldcreate shorter simpler function)


testCodegen2( dataToTx, 1,tx.messageCharacters, tx.frameLength, hPreambleDemod.NumSymbols ,tx.padBits)
%compilesdru('testCodegen2','mex','-args','{ dataToTx, 1, coder.Constant(tx.messageCharacters), coder.Constant(tx.frameLength), coder.Constant(hPreambleDemod.NumSymbols) ,coder.Constant(tx.padBits)}')
%testCodegen2_mex( dataToTx, 1,tx.messageCharacters, tx.frameLength, hPreambleDemod.NumSymbols ,tx.padBits)

x=PHYTransmitter; step(x,1);
destNode = 1;originNode = 1;
inputPayloadMessage='hello';
if length(inputPayloadMessage) < 74
   uniqueID = char(randi([0 (2^7)-1],1,1));%Add additional character to differentiate messages
   destNodeChar = char(48 + destNode);
   originNodeChar = char(48 + originNode);
   payloadMessage = [inputPayloadMessage,originNodeChar,destNodeChar,uniqueID,'EOF',repmat('-',1,74 - length(inputPayloadMessage))];
else
    fprintf('ERROR: Message incorrect format\n');
    return;
end
originalData = OFDMletters2bits(payloadMessage);

[frame,padBits,numDataSymbols,frameLength] = x.CreateOFDMFrame(originalData);

h=PHYReceiver;
%h.ReceiveBufferLength = 6*400
h.NumFrames=1;%numDataSymbols;
h.MessageCharacters = length(payloadMessage);
h.FrameLength = frameLength;
h.NumDataSymbolsPerFrame = numDataSymbols;
h.padBits = padBits;

%h.HWAttached = true;
%output = step(h);

output = step(h,frame);
fprintf('%s\n',output);
