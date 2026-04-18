## x86 C Windows32 API examples
- based on [other Github x86 ASM using Win32 API](https://github.com/google85/x86-asm-using-win32-api/)

* [x] `msgbox`

##

- using custom `.devcontainer` that includes:
    - [hexdump](from `bsdmainutils` package)
    - `binutils-mingw-w64-i686` for Windows API files like `utilapiset.h`
- run on `cmd.exe`


#

### Usage:
```bash
cd msgbox
make build

# run [works in wsl too]
./build/msgbox.exe
```
