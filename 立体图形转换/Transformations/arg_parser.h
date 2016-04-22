#ifndef __ARG_PARSER_H__
#define __ARG_PARSER_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
class ArgParser
{
public:
	ArgParser(int argc,const char **argv)
	{
		DefaultValues();
		ParseArguments(argc,argv);
	}
	~ArgParser() {}
private:
	ArgParser() { assert(0); } // don't use this constructor

	// HELPER FUNCTIONS
	void DefaultValues() {
		input_file = NULL;
		size_x = 100, size_y = 100;
		output_file = NULL;
		depth_x = 10, depth_y = 10;
		depth_file = NULL;
		normals_file = NULL;
		n = 0;
		isShadeBack = false;
	}
	void ParseArguments(int argc,const char **argv) {
		for (int i = 1; i < argc; i++) {
			if (!strcmp(argv[i], "-input")) {
				i++; assert(i < argc);
				input_file = new char[strlen(argv[i]) + 1];
				//input_file = argv[i];
				strcpy_s(input_file, strlen(argv[i]) + 1, argv[i]);
			}
			else if (!strcmp(argv[i], "-size")) {
				i++; assert(i < argc);
				size_x = atoi(argv[i]);
				i++; assert(i < argc);
				size_y = atoi(argv[i]);
			}
			else if (!strcmp(argv[i], "-output")) {
				i++; assert(i < argc);
				output_file = new char[strlen(argv[i]) + 1];
				//output_file = argv[i];
				strcpy_s(output_file, strlen(argv[i]) + 1, argv[i]);
			}
			else if (!strcmp(argv[i], "-depth")) {
				i++; assert(i < argc);
				depth_x = atoi(argv[i]);
				i++; assert(i < argc);
				depth_y = atoi(argv[i]);
				i++; assert(i < argc);
				depth_file = new char[strlen(argv[i]) + 1];
				strcpy_s(depth_file, strlen(argv[i]) + 1, argv[i]);
			}
			else if (!strcmp(argv[i], "-normals")) {
				i++; assert(i < argc);
				normals_file = new char[strlen(argv[i]) + 1];
				//output_file = argv[i];
				strcpy_s(normals_file, strlen(argv[i]) + 1, argv[i]);
			}
			else if (!strcmp(argv[i], "-shade_back")){
				isShadeBack = true;
			}
			else {
				printf("whoops error with command line argument %d: '%s'\n", i, argv[i]);
				assert(0);
			}
		}
	}
public:
	char *input_file;
	int size_x = 100, size_y;
	char *output_file;
	int depth_x, depth_y;
	char *depth_file;
	char *normals_file;
	int n;
	bool isShadeBack;
};

#endif