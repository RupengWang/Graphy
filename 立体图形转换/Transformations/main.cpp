#include "image.h"
#include "arg_parser.h"
#include "scene_parser.h"
#include "output_tga.h"
#include <stdlib.h>
#include <iostream>


using namespace std;

int main(int argc, const char **argv)
{
	ArgParser *args = new ArgParser(argc, argv);
	SceneParser *scenes = new SceneParser(args->input_file);
	OutputTGA *output_TGA = new OutputTGA(args, scenes);
	output_TGA->output(args, scenes);

	delete scenes;
	delete args;
	return 0;
}