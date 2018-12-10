#include<cstdio>
#include<cstring>
int lookup_keyword(char const * const word, char const *keyword[], int const size) {
	char  const **kwp;
	for (kwp = keyword; kwp < keyword + size; kwp++)
		if (strcmp(word, *kwp) == 0)
			return kwp - keyword;
	return -1;
}

int main() {
	char const *keyword[] = { "do","for","if","register","return","switch","while" };
	int size = (sizeof(keyword) / sizeof(keyword[0]));
	char word[10];
	scanf("%s", word);
	printf("%d", lookup_keyword(word, keyword, size));
}
