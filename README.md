# GameBoyTemplate
Project template for Game Boy / GBC games written using GBDK.

## How to Build the ROM

### Depedencies
* [GBDK-2020](https://github.com/gbdk-2020/gbdk-2020) - The Game Boy Development
  kit. Includes the libraries and binaries for C development on the Game Boy.
* [GNU Make](https://gnuwin32.sourceforge.net/packages/make.htm) - Build system
tool (installation should only be required on Windows).

### Use Make to Build the ROM
Update the `MakeFile` or define a shell variable named `GBDK_HOME` pointing to
the directory where you installed GBDK.

Once the tools are installed and the home directory is defined, all you have
to do is run `make` from the project's root directory:
