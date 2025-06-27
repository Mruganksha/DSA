//reverse word
//logic: 1st) Remove extra spaces (leading, trailing spaces)
//2)Reverse entire string
//3)reverse each string

void reverse(char *str, int start, int end){
	while(start < end){
		char temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}
}

char* trimspaces(const char* str){
	int len = strlen(str);
	char* trimmed = (char*)malloc(len + 1);
	int i = 0, j = 0;
	
	//skip leading spaces
	while(str[i] && isspace(str[i])) i;
	
	int spaceFlag = 0;
	while (str[i]) {
        if (!isspace(str[i])) {
            trimmed[j++] = str[i++];
            spaceFlag = 0;
        } else {
            if (spaceFlag == 0) {
                trimmed[j++] = ' '; // only one space
                spaceFlag = 1;
            }
            i++;
        }
    }

    // Remove trailing space
    if (j > 0 && trimmed[j - 1] == ' ')
        j--;

    trimmed[j] = '\0';
    return trimmed;
}

char* reverseWords(const char* input) {
    char* cleaned = trimSpaces(input);
    int len = strlen(cleaned);

    // Reverse entire string
    reverse(cleaned, 0, len - 1);

    // Reverse each word
    int start = 0;
    for (int i = 0; i <= len; i++) {
        if (cleaned[i] == ' ' || cleaned[i] == '\0') {
            reverse(cleaned, start, i - 1);
            start = i + 1;
        }
    }

    return cleaned; // return the modified string
}
