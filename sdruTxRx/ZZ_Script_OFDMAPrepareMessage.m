% clear all;

clc;

message_UE1 = '1st Message';
message_UE2 = '2nd Message';
message_UE3 = '3rd Message';
message_UE4 = '4th Message';

numUsers = 3;

OriginNodes = [1 2 3];

DestNodes = [4 5 6];

messageToTx = OFDMAPrepareMessage(OriginNodes,DestNodes,message_UE1,message_UE2,message_UE3,message_UE4,numUsers);

obj = OFDMPHYBase;

r = OFDMASignalGenerator(obj,messageToTx);
