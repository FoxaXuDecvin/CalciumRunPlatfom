#include"TextProces.h"
#include"Verinfo.h"
#include"CalciumKernel.h"

using namespace std;

int main(int argc,char* argv[]){
    if(argc == 1){
        cout << "Calcium Run Platfom. VerCode " << Str_VerCode <<endl;
        cout << "Copyright FoxaXu Software@" <<endl;
        cout << "Version :     " << VersionCode <<endl;
        cout << "Code Name :   " << CodeName << endl;
        cout << "Info :        " << VerNotice << endl;
        cout << "Calcium is a Open Source Software. if you want get more info" <<endl;
        cout << "Please visit https://calcium.foxaxu.com" << endl;
        cout << "Please add \"-cascript <RunFile>\" in command" <<endl;
        cout << endl;
        cout << endl;
        return 1;
    }
    paragetsize = 0;
    charnxmark = 0;
    cout << endl;

    for(int readargc = 1,fileswitch = 0;readargc != argc;readargc++){
        readbuffer = argv[readargc];
        parameterGet = parameterGet + " " + readbuffer;

        if (fileswitch == 1){
            RunScript = readbuffer;
            fileswitch = 0;
            continue;
        }

        if (readbuffer == "-cascript"){
            fileswitch = 1;
            continue;
        }
        if (readbuffer == "-version"){
            charnxmark = 1;
            cout << "Calcium Run Platfom" << endl;
            cout << "Version Info" << endl;
            cout << "Version : " << CodeName << "  " << Str_VerCode << endl;
            cout << "Developer Info :  " << VerNotice << endl;
            cout << "Run Platfom :  " << RunPlatfom << endl;
            cout << "Copyright FoxaXu Software" << endl;
            afterRollExit = 1;
            break;
        }

        cout << "Unknown Parameter :  " << readbuffer << endl;
    }

    if (charnxmark == 1){
        cout << endl;
    }
    if (afterRollExit == 1){
        return 0;
    }

    if (RunScript == "NOSET"){
        cout << "Use \"-cascript <file>\" Run Script" << endl;
        return 0;
    }
    if(check_file_existence(RunScript)){}
    else {
        cout << "Cannot Find :  " << RunScript << endl;
        cout << "Check your type and try again" << endl;
        return 0;
    }

    int a = rollscript(RunScript);
    if (a == 1001){
        //Return UnknownError
        cout << "Script Return Error" << endl;
    }
    if (a == 1002){
        //Return FileDestroy
        cout << "Script Run Error" << endl;
        cout << "Read Failed :  This File is Destroy." <<endl;
        cout << "File : " << RunScript << endl;
    }
    return 0;
}