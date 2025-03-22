void notice(){
	printf("\x1b[97m");
	printf("\x1b[5m");
	printf("\e[1;1H\e[2J");
	printf("Conch Shell\n"); //Name
	printf("\x1b[11m"); //Purple version number
	printf("0.0.3\n"); //Version
	fflush(stdout);
}
