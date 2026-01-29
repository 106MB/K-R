// Convert newline and tab into visible characters as string t is copied to string s
// using switch
#include <stdio.h>
#define LIM 100

void escape(char s[], char t[]);
int main(){
	
	 char s[LIM] = "";
	 char t[LIM] = "";

	 while((fgets(s, LIM - 1, stdin)) != NULL && s[0] != EOF)
	 {
		 escape(s,t);
		 printf("%s\n", t);
	 } 

}


void escape(char s[], char t[]){
	int i, j;
	for(i = 0, j = 0; s[i] != '\0' && j < LIM - 1; ){
		switch(s[i]){
			case '\n':
				i++;
				t[j++] = '\\';
				t[j++] = 'n';
				break;
			case '\t':
				i++;
				t[j++] = '\\';
				t[j++] = 't';
				break;
			default:
				t[j++] = s[i++];
				break;
		}
	}
	t[j] = '\0';
}
