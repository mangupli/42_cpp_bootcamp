#include <fstream>
#include <iostream>

int displayError(int errorNo)
{
    switch(errorNo)
    {
        case 1:
            std::cerr << "Excected 4 arguments: ./replace <filename> <string1> <string2>" << std::endl;
            break;
        case 2:
            std::cerr << "Error when opening file for reading" << std::endl;
            break;
        case 3:
            std::cerr << "Error when opening file for writing" << std::endl;
            break;
        case 4:
            std::cerr << "Invalid string (empty)" << std::endl;
            break;
    }
    return (errorNo);
}

int findAndReplaceString(std::string const &srcFilename, std::string const &dstFilename, std::string const &srcString, std::string const &dstString)
{
    std::ifstream srcFile(srcFilename);
    if(!srcFile)
        return(displayError(2));

    std::ofstream dstFile(dstFilename);
    if (!dstFile)
        return (displayError(3));

    std::string::size_type  index;
    std::string             bufferString;
   
    while(srcFile)
    {
        getline(srcFile, bufferString);

        index = 0;

        while (true)
        {
             /* Locate the substring to replace. */
            index = bufferString.find(srcString, index);

            if (index == std::string::npos) break;

            /* Make the replacement. */
            bufferString.replace(index, srcString.length(), dstString);

            /* Advance index forward so the next iteration doesn't pick it up as well. */
            index += dstString.length();
        }
        dstFile << bufferString;
        if (srcFile)
            dstFile << std::endl;
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return (displayError(1));

    std::string const srcFilename(argv[1]);
    std::string const dstFilename(srcFilename + std::string(".replace"));
    std::string const srcString(argv[2]);
    std::string const dstString(argv[3]);

    if (srcString.empty() || dstString.empty())
        return (displayError(4));

    int ret = findAndReplaceString(srcFilename, dstFilename, srcString, dstString);
    return (ret);
}