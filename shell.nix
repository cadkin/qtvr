# shell.nix
{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
    buildInputs = [
        pkgs.qt5.full
        pkgs.qtcreator
        pkgs.cmake
        pkgs.binutils
        pkgs.gcc
        pkgs.libGL
        pkgs.pkgconfig
    ];
}
