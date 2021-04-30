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
        pkgs.gst_all_1.gst-plugins-bad
        pkgs.gst_all_1.gst-plugins-good
        pkgs.gst_all_1.gst-plugins-ugly
        pkgs.gst_all_1.gst-plugins-base
        pkgs.libv4l
    ];
}
