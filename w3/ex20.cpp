#include <stdio.h>
#include <string.h>
#include <vector>

int main(){
	char x[255];
	char* token;
	char* tokenized[20];

	//read a line
	printf("Enter a sentence\n");
	fgets(x, 199, stdin);
	x[strlen(x) - 1] = 0;
	printf("You entered %s\n", x);

	//tokenize
	token = strtok(x, " "); // get the first token
	int i = 0;
	for (;;) {
		i++;
		tokenized[i - 1] = token;
		token = strtok(NULL, " "); // get the next token
		if (token == NULL) break;
	}

	//display tokens
	printf("There were %d words : ", i);
	for (int j = 0; j < i; j++)
		printf("%s ", tokenized[j]);

	//compute frequency
	std::vector<std::pair<char*, int>> freq;
	freq.push_back(std::make_pair(tokenized[0], 1));
	for (int j = 1; j < i; j++) {
		int k;
		for (k = 0; k < freq.size(); k++) {
			if (!strcmp(freq[k].first, tokenized[j])) {
				freq[k].second++;
				break;
			}
		}
		if (k == freq.size())
			freq.push_back(std::make_pair(tokenized[j], 1));
	}
	printf("\nFrequencies :");
	for (int j = 0; j < freq.size(); j++)
		printf("%s %d ", freq[j].first, freq[j].second);

	//compute max frequency word and display it
	int max_index = 0;
	for (int j = 1; j < freq.size(); j++)
		if (freq[j].second > freq[max_index].second)
			max_index = j;
	printf("\nThe word with the max freq : %s", freq[max_index].first);
}
