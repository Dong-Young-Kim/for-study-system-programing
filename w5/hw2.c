#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void main(){
	char ChunkID[10];
	int ChunkSize;
	char Format[10];
	char Subchuck1ID[10];
	int Subchuck1Size;
	short AudioFormat;
	short NumChannels;
	int SampleRate;
	int ByteRate;
	short BlockAlign;
	short BitsPerSample;
	char Subchuck2ID[10];
	int Subchunk2Size;

	int x, y;
	x = open("./swvader03.wav", O_RDONLY, 07777);

    	y = read(x, ChunkID, 4);
    	ChunkID[y] = 0;
    	y = read(x, &ChunkSize, 4);
    	y = read(x, Format, 4);
    	Format[y] = 0;
    	y = read(x, Subchuck1ID, 4);
    	Subchuck1ID[y] = 0;
    	y = read(x, &Subchuck1Size, 4);
	y = read(x, &AudioFormat, 2);
	y = read(x, &NumChannels, 2);
	y = read(x, &SampleRate, 4);
	y = read(x, &ByteRate, 4);
	y = read(x, &BlockAlign, 2);
	y = read(x, &BitsPerSample, 2);
	y = read(x, Subchuck2ID, 4);
	Subchuck2ID[y] = 0;
	y = read(x, &Subchunk2Size, 4);

	printf("ChunkID : %s \n", ChunkID);
    	printf("ChunkSize : %d \n", ChunkSize);
	printf("Format : %s \n", Format);
    	printf("Subchunk1ID : %s \n", Subchuck1ID);
    	printf("Subchunk1Size : %d \n", Subchuck1Size);
    	printf("AudioFormat : %d \n", AudioFormat);
    	printf("NumChannels : %d \n", NumChannels);
	printf("SampleRate : %d \n", SampleRate);
    	printf("ByteRate : %d \n", ByteRate);
    	printf("BlockAlign : %d \n", BlockAlign);
    	printf("BitsPerSample : %d \n", BitsPerSample);
    	printf("Subchunk2ID : %s \n", Subchuck2ID);
    	printf("Subchunk2Size : %d \n", Subchunk2Size);
}
