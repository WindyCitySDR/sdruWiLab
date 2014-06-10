function value = mccTXTest( ObjSDRuReceiver )

persistent objSDRuReceiver;

%messagePointer.Object = 'WiLab';
messagePointer = 'WiLab';

fprintf('Reached\n');

%SDRuTX = comm.SDRuTransmitter('InterpolationFactor',20);
%SDRuTX = comm.SDRuReceiver('DecimationFactor',20);
% Setup transmitter

%ObjSDRuTransmitter = comm.SDRuTransmitter('192.168.10.2', ...
%    'CenterFrequency',      2.2e9, ...
%    'InterpolationFactor',  20,...
%    'Gain',                 25);

%ObjSDRuReceiver = comm.SDRuReceiver( '192.168.10.2', ...
%    'CenterFrequency',      2.2e9, ...
%    'DecimationFactor',     20,...
%    'FrameLength',          5120,...
%    'OutputDataType',       'double',...
%    'Gain',                 18);

x = dsp.FFT;
%ObjSDRuReceiver = create_obj;

data = randn(5120,1);

for k=1:1e4
   %step(SDRuTX,data); 
   step(ObjSDRuReceiver); 
end

value = 'ImAlive';

end
