filename='C:\Users\Redzer0\Desktop\2L48SACD_14_mch_96k.flac';
[y, Fs]=audioread(filename);
Fs = 8000;
nBits=24;
playerObj=audioplayer(y(:,1), Fs, nBits);
get(playerObj);
play(playerObj);