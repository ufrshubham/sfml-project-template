# SFML Project Template

A cross-platform template for C++ SFML projects using cmake

## How to use?

### Clone

There are two ways to use this project template. You can either create a your own GitHub repo using this template (very similar to forking) or your can directly clone this repo on your local machine. Here are steps for both these ways:

1. GitHub repo using template

    - Make sure you are logged into your GitHub account.

    - Click on the "Use this template" button.

        ![Step2](readme-assets/use-this-template-button.png)

    - Provide a name for your new repo.

    - Click "Create repositoy from template".

    - Clone your new repo recursively.

    ```bash
    git clone --recursive <your-repo-link-here>
    ```

2. Local repo by direcly cloning

    Step 1. Clone this repo recusrively using this command:

    ```bash
    git clone --recursive https://github.com/ufrshubham/sfml-project-template.git
    ```

Note: If you've already cloned this repo without using `--recursive` flag, just run `git submodule update --init` to update the submodules.

### Code

- Source files should be placed under `src` directory.

- Header files should be placed under `include` directory. Header `Version.hpp` can be remove completely as it is just for demo.

- Source code for SFML is pulled as a submodule under `vendors/sfml` and is built along with your code.

- Assets like images, audio and fonts can be placed under `resources` directory. If you choose to use a custom directory for this, you'll have to handle how your executable finds those assets. The demo code in `src/main.cpp` programitically changes the working directory to the path where `resources` directory is located (see function `modifyCurrentWorkingDirectory()`).

### Build

- Make a directory for build in your project root.

    ```bash
    cmake -E make_directory ./build
    ```

- Go to the build directory.

    ```bash
    cd build/
    ```

- Generate project files (For debug builds, replace `Release` with `Debug`).

    ```bash
    cmake .. -DCMAKE_BUILD_TYPE=Release
    ```

- Build (For debug builds, replace `Release` with `Debug`).

    ```bash
    cmake --build . --config Release
    ```

- You should find the executables under `build/bin`
