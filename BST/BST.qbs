import qbs

CppApplication {
    consoleApplication: true
    files: [
        "binary_search_tree.h",
        "interface.cpp",
        "interface.h",
        "main.cpp",
        "measuring_time.h",
        "tests.hpp",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
