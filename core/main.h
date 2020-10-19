/*
char *colour(int color_no){
	char *colours[4];
	colours[0] = "\033[0m";  // Non color.
	colours[1] = "\033[91m"; // Red color.
	colours[2] = "\033[92m"; // Green color.
	colours[3] = "\033[93m"; // Yellow color.
	colours[4] = "\033[94m"; // Blue color.

	return colours[color_no];
};
*/

void reset(){
	printf("\033[0m");
};

void greay(){
	printf("\033[90m");
};

void red(){
	printf("\033[91m");
};


void green(){
	printf("\033[92m");
};

void yellow(){
	printf("\033[93m");
};

void blue(){
	printf("\033[94m");
};


void error(char *errmsg){
	red();
	perror(errmsg);
	reset();
	exit(0);
};

void banner_server(){
	red();
	printf("░██████╗███████╗██████╗░██╗░░░██╗███████╗██████╗░\n");
	printf("██╔════╝██╔════╝██╔══██╗██║░░░██║██╔════╝██╔══██╗\n");
	printf("╚█████╗░█████╗░░██████╔╝╚██╗░██╔╝█████╗░░██████╔╝\n");
	printf("░╚═══██╗██╔══╝░░██╔══██╗░╚████╔╝░██╔══╝░░██╔══██╗\n");
	printf("██████╔╝███████╗██║░░██║░░╚██╔╝░░███████╗██║░░██║\n");
	printf("╚═════╝░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝\n");
	greay();
	printf("				@ansanbinoy\n");
	reset();

};

void banner_client(){
	red();
	printf("░█████╗░██╗░░░░░██╗███████╗███╗░░██╗████████╗\n");
	printf("██╔══██╗██║░░░░░██║██╔════╝████╗░██║╚══██╔══╝\n");
	printf("██║░░╚═╝██║░░░░░██║█████╗░░██╔██╗██║░░░██║░░░\n");
	printf("██║░░██╗██║░░░░░██║██╔══╝░░██║╚████║░░░██║░░░\n");
	printf("╚█████╔╝███████╗██║███████╗██║░╚███║░░░██║░░░\n");
	printf("░╚════╝░╚══════╝╚═╝╚══════╝╚═╝░░╚══╝░░░╚═╝░░░\n");
	greay();
	printf("                                @ansanbinoy\n");
	reset();
};

void check_args_c(int args){
	if (args < 3){
		banner_client();
		red();
		error("Host and Port is not provided!.\n[+] ./client host port ");	
		reset();
	};
};

void check_args_s(int args){
	if (args < 3){
		reset();
		banner_server();
		red();
		error("Host and Port is not provided!.\n[+] ./server host port ");
		reset();
	};
};
