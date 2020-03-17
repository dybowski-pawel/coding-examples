//
// Created by pawel on 17.03.20.
//

#ifndef EXAMPLES_VERSION_H
#define EXAMPLES_VERSION_H

#include <string>

class Version {
public:

    /*******************************************************************************
     * Get current code version
     *
     * @return Current version in format major.minor.patch+build
     ******************************************************************************/
    static std::string getVersion();

    /*******************************************************************************
     * Calculate value of current code version.
     *
     * Obtained value can be used to determine which version of code is newer
     *
     * @return Value of version in format major*10000+minor*100+patch
     ******************************************************************************/
    static int calculateValue();

private:
    Version() = default;
    Version(Version const&);
    void operator=(Version const&);

    static void initialize();
    static std::string VERSION_MAJOR;
    static std::string VERSION_MINOR;
    static std::string VERSION_PATCH;
    static std::string VERSION_BUILD;
    static bool initialized;
};

#endif //EXAMPLES_VERSION_H
