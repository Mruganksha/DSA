//Remove outermost paranthesis
//A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

char* removeOuterParentheses(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc(len + 1);
    int index = 0; //for result
    int balance = 0; //tracks the level of missing

    for(int i = 0; i < len; ++i){
        if(s[i] == '('){
            if(balance > 0){
                result[index++] = s[i];
            }
            balance++;
        } else if(s[i] == ')'){
            balance--;
            if(balance > 0){
                result[index++] = s[i];
            }
        }
    }
    result[index] = '\0';
    return result;
}
