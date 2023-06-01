#include <stdio.h>
#include <string.h>

int main()
{
	// Declare a 2D char array to stores inputs words
	// Maximum 100 input words and each word maximum 10 chars
	char words[100][10];
	char temp[10];
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", words[i]);
	}

	// Bubble sort to sort the words
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (strcmp(words[j], words[j+1]) > 0) {
				strcpy(temp, words[j]);
				strcpy(words[j], words[j+1]);
				strcpy(words[j+1], temp);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%s\n", words[i]);
	}

	return 0;
}
