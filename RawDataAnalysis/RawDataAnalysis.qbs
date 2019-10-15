import qbs

CppApplication {
    consoleApplication: true
    files: [
        "filecontrol.cpp",
        "filecontrol.h",
        "main.cpp",
        "postprocessing.cpp",
        "postprocessing.h",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
