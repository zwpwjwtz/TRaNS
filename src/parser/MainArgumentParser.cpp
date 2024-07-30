#include "MainArgumentParser.h"
#include <argp.h>


static char MainArgumentParser_doc[] = \
    "TRaNS - Transcriptional Regulation Network Simulator";

static char MainArgumentParser_args_doc[] = \
    "TOPOLOGY_FILE PARAMETER_FILE TIME_FILE";

static argp_option MainArgumentParser_options[] = 
{
    {"help", 'h', 0, 0, "Show help"}, 
    {"initial", 'i', "FILE", 0, "Specify the initial values from FILE"}, 
    {"output", 'o', "FILE", 0, 
     "Output the result to FILE instead of standard output"}, 
    {0}
};

static error_t MainArgumentParser_parse(int key, char *arg, 
                                        argp_state *state)
{
    MainArgument* arguments = static_cast<MainArgument*>(state->input);
    switch (key)
    {
        case 'h':
            argp_usage(state);
            break;
        case 'i':
            arguments->initialFilename.assign(arg);
            break;
        case 't':
            arguments->timeFilename.assign(arg);
            break;
        case 'o':
            arguments->outputFilename.assign(arg);
            break;
        case ARGP_KEY_ARG:
            switch (state->arg_num)
            {
                case 0:
                    arguments->topologyFilename = arg;
                    break;
                case 1:
                    arguments->parameterFilename = arg;
                    break;
                case 2:
                    arguments->timeFilename = arg;
                    break;
                default:
                    argp_usage(state);
            }
            break;
        case ARGP_KEY_END:
            if (state->arg_num < 3)
                argp_usage(state);
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static argp MainArgumentParser_argp = 
{
    MainArgumentParser_options, 
    MainArgumentParser_parse, 
    MainArgumentParser_args_doc,
    MainArgumentParser_doc
};

MainArgument MainArgumentParser::parse(int argc, char *argv[])
{
    MainArgument arguments;
    argp_parse(&MainArgumentParser_argp, argc, argv, 0, 0, &arguments);
    return arguments;
}

