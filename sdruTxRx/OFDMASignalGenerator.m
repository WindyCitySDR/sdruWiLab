function r = OFDMASignalGenerator(obj,messageToTx)
% WRITE HELP HERE!!!


% The number of frames is equal to the number of users, since each one of 
% the user's messages has 80 characters, exactly one frame
numFrames = messageToTx.numUsers;

%% Convert to bits

% Initialize matrix
originalData = zeros(messageToTx.numUsers,7*size(messageToTx.messageText,2));

for user = 1:messageToTx.numUsers
    
    % Convert to bits, in the matrix form
    UsersOriginalData = obj.OFDMletters2bits(messageToTx.messageText(user,:));
    
    % Reshape into a vector
    originalData(user,:) = reshape(UsersOriginalData.',size(UsersOriginalData,1)*size(UsersOriginalData,2),1);
    
end

%% Add CRC

% The CRC length is 4, which means that the final bit stream (including 
% CRC) will have 564 bits. This is a very convenient number, because it
% makes user multiplexing easier, since 564 is divisible by 2, 3 and 4, and
% the maximum number of users is 4.

% Generate CRC object handle
hGen = comm.CRCGenerator([1 0 0 1 1], 'ChecksumsPerFrame',1);

% Initialize matrix. Remember to change added number if CRC length changes!
dataWithCRC = zeros(messageToTx.numUsers,length(originalData) + 4);

for user = 1:messageToTx.numUsers
    dataWithCRC(user,:) = step(hGen, originalData(user,:)');% Add CRC
end

%% BPSK Modulate

% Construct modulator for each subcarrier
hMod = comm.BPSKModulator; % BPSK

% Initialize matrix, needs to change if modulation scheme changes
modData = zeros(size(dataWithCRC));

for user = 1:messageToTx.numUsers
    % Apply modulator for each subcarrier
    modData(user,:) = step(hMod, dataWithCRC(user,:)');
end

%% User multiplex

% % Define number of carriers per user
% carriersPerUser = obj.numCarriers/messageToTx.numUsers; %%%% Later?

% Define number of bits per user per frame
bitAllocation = size(modData,2)/messageToTx.numUsers;

% Reshape to break each user's stream
reshaped_modData = reshape(modData',bitAllocation,messageToTx.numUsers ^ 2);

% Initialize matrix
muxData = zeros(size(modData));
muxFrame = zeros(1,size(modData,2));

for frame = 1:numFrames
    
    for user = 1:messageToTx.numUsers
        % Define one multiplexed frame
        muxFrame((user-1)*bitAllocation + 1 : user*bitAllocation) = ...
            reshaped_modData(:,frame + (user-1)*messageToTx.numUsers)';
        
    end
    
    muxData(frame,:) = muxFrame;
    
end

%% OFDM Modulate and add Pilots

% Pad IFFT
padBits = numCarriers - mod(length(muxData,2),numCarriers);
if padBits == numCarriers
    padBits = 0;
end
muxData = [muxData repmat(step(hMod,randi([0 1],padBits,1)),numFrames,1)];



%% Create preambles
obj.CreatePreambles;

%% Create and add preambles

r = muxData;

end