<<<<<<< HEAD
!export LD_LIBRARY_PATH=/opt/MATLAB/R2013a/runtime/glnxa64/

decimation = 20;
compilesdru('testPHYReceive_per','mex','-args','{decimation}');
compilesdru('testPHYTransmit','mex');
=======
%!export LD_LIBRARY_PATH=/opt/MATLAB/R2013a/runtime/glnxa64/
!export LD_LIBRARY_PATH=/usr/local/MATLAB/R2013b/runtime/glnxa64/

decimation = 20;


%compilesdru('testPHYReceive_per','mex','-args','{decimation}');
codegen testPHYReceive_per -config:lib -args {decimation}


%compilesdru('testPHYTransmit','mex');
codegen testPHYTransmit -config:dll
>>>>>>> phyObj

% mcc -v -W cpplib:libtestPHYReceive -T link:lib testPHYReceive.m...
%                                                generateOFDMSignal.m...
%                                                generateOFDMSignal_TX2.m...
%                                                OFDMbits2letters.m...
%                                                OFDMletters2bits.m...
%                                                initializeOFDMSyncMemory_sdr.m...
%                                                PHYReceive.m...
%                                                locateOFDMFrame_sdr.m...
%                                                coarseOFDMFreqEst_sdr.m...
%                                                equalizeOFDM.m...
%                                                demodOFDMSubcarriers_sdr.m ...
%                                                CreateTXRX.m...
%                                                BoardIdCapiEnumT.m...
%                                                OFDMBase.m...
%                                                OFDMModulator.m...
%                                                OFDMDemodulator.m...
%                                                SDRuReceiver.p

<<<<<<< HEAD
mcc -v -W cpplib:libMEXtestPHY -T link:lib MEXtestPHYReceive_per.m MEXtestPHYTransmit.m

!sudo cp libMEXtestPHY.so /opt/MATLAB/R2013a/runtime/glnxa64/

mbuild phyreceive_threads_per.cpp libMEXtestPHY.so
!./phyreceive_threads_per
=======
%mcc -v -W cpplib:libMEXtestPHY -T link:lib MEXtestPHYReceive_per.m MEXtestPHYTransmit.m

!rm -rf codegen/dll/combo/*
!cp -r codegen/dll/testPHYReceive_per/* codegen/dll/combo/
!cp -r codegen/dll/testPHYTransmit/* codegen/dll/combo/
!cp phyreceive_threads_per2.cpp codegen/dll/combo/
!cp -r /home/sdruser/git/traviscollins/SupportPackage/sdru/include/* codegen/dll/combo/

%!sudo cp libMEXtestPHY.so /opt/MATLAB/R2013a/runtime/glnxa64/
cd codegen/dll/combo/
!sudo cp testPHYReceive_per.so /usr/local/MATLAB/R2013b/runtime/glnxa64/
!sudo cp testPHYTransmit.so /usr/local/MATLAB/R2013b/runtime/glnxa64/

mbuild phyreceive_threads_per2.cpp testPHYTransmit.so testPHYReceive_per.so

!./phyreceive_threads_per2
>>>>>>> phyObj
