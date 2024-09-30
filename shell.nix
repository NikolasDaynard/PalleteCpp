{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.SDL2           # SDL2 library
    pkgs.SDL2_image     # SDL2_image for loading images
    pkgs.SDL2_ttf       # SDL2_ttf for fonts
    pkgs.SDL2_mixer     # SDL2_mixer for sound
    pkgs.gcc            # GCC compiler
    pkgs.cmake          # CMake for project management
  ];

  # Optionally add SDL2 development documentation
  shellHook = ''
    echo "SDL2 environment loaded. Ready for development!"
  '';
}
