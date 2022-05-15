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
	FILE *fout = fopen("./sw3-wav.txt", "w");

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

	fprintf(fout, "ChunkID : %s \n", ChunkID);
    	fprintf(fout, "ChunkSize : %d \n", ChunkSize);
	fprintf(fout, "Format : %s \n", Format);
    	fprintf(fout, "Subchunk1ID : %s \n", Subchuck1ID);
    	fprintf(fout, "Subchunk1Size : %d \n", Subchuck1Size);
    	fprintf(fout, "AudioFormat : %d \n", AudioFormat);
    	fprintf(fout, "NumChannels : %d \n", NumChannels);
	fprintf(fout, "SampleRate : %d \n", SampleRate);
    	fprintf(fout, "ByteRate : %d \n", ByteRate);
    	fprintf(fout, "BlockAlign : %d \n", BlockAlign);
    	fprintf(fout, "BitsPerSample : %d \n", BitsPerSample);
    	fprintf(fout, "Subchunk2ID : %s \n", Subchuck2ID);
    	fprintf(fout, "Subchunk2Size : %d \n", Subchunk2Size);
}
