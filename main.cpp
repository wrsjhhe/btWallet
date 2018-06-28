#include <iostream>
#include <string>
#include <boost/program_options.hpp>

namespace  bpo = boost::program_options;

bool parseParams(int argc,char *argv[])
{
    bpo::options_description opts("options");

    bpo::variables_map vm;

    opts.add_options()
            ("createwallet", "create a new wallet")
            ("help", "help message")
            ("name",bpo::value< std::string>(),"the name of wallet")
            ("password",bpo::value< std::string>(),"the password of wallet");

    bpo::positional_options_description p;
    p.add("name",0).add("password",1);


    try{
        bpo::store(bpo::parse_command_line(argc, argv, opts), vm);
    }
    catch(...){
        std::cout << "输入的参数中存在未定义的选项！\n";
        exit(-1);
    }

    if(vm.count("help") ){
        //自动打印所有的选项信息
        std::cout << opts << std::endl;
        exit(0);
    }



    if(vm.count("createwallet"))
    {
        if(vm.count("name"))
        {
            std::cout << vm["name"].as<std::string>() << std::endl;
        }
        if(vm.count("password"))
        {
            std::cout << vm["password"].as<std::string>() << std::endl;
        }

    }

}


int main(int argc,char *argv[])
{
    if(argc < 2)
        return -1;
    parseParams(argc,argv);

    return 0;
}