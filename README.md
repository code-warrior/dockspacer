<meta charset="utf-8">
# Dockspacer for Mac OS X

v1.0.0

![Dockspacer screenshot](img/dockspacer.png "Dockspacer screenshot")

This Terminal-level program creates empty items in your Dock — either in the Applications area, or near the Recycle Bin — that you can use as spacers in order to delimit logical groupings of items. For example, you may have Sublime Text 3 and TextWrangler in your Dock, sitting next to each other, and you want to separate them from other Dock items with spacers.

**Note**: This program does not remove any Dock items you create; you’ll need to remove unwanted Dock spacers manually.

— Roy Vanegas (roy@thecodeeducators.com)

## Installation (Easiest)

1. You can download `dockspacer` by running the following command from The Terminal:

        curl -OL https://github.com/code-warrior/dockspacer/raw/master/dockspacer

2. Change permissions:

        chmod 755 dockspacer

3. Run the program:

        ./dockspacer

3. Your computer will flash when it’s done. This is the result of restarting The Dock and is normal.

## Installation (Easy)

1. Download and unzip [`dockspacer-master.zip`](https://github.com/code-warrior/dockspacer/archive/master.zip).

2. Open The Terminal and navigate to the unzipped folder.

3. Move the binary into your local environment:

        sudo cp dockspacer /usr/local/bin

4. Run `dockspacer` from The Terminal:

        dockspacer

5. Your computer will flash when it’s done. This is the result of restarting The Dock and is normal.

## Build

        make

or

        gcc -Wall main.c libs/create_dockspacer.c libs/stoi.c -o dockspacer

## Verified On...
* Mac OS X 10.11
* Mac OS X 10.10
* Mac OS X 10.9.4
* Mac OS X 10.8.5
