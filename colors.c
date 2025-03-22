void background(char* color){
	printf("\x1b[48;5;");
	printf("%s",color);
	printf("m");
}
void foreground(char* color){
	printf("\x1b[38;5;");
	printf("%s",color);
	printf("m");
}