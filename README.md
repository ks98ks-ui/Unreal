# First

Unreal Engine study project built with C++ gameplay code and Unreal content assets.

## Overview

This repository contains a personal Unreal project that combines engine content, Blueprint assets, and custom C++ classes.
The project currently includes gameplay code and content for item systems plus multiple play variants such as combat, platforming, and side-scrolling.

## Project Structure

- `First.uproject`: Unreal project entry file
- `Source/First`: C++ gameplay classes and module code
- `Content/`: Unreal assets, maps, Blueprints, animations, audio, and starter content
- `Config/`: Unreal project configuration files

## Development Workflow

1. Open `First.uproject` in Unreal Engine.
2. Generate Visual Studio project files if needed.
3. Build and run the editor from Visual Studio or Unreal Editor.
4. Test gameplay changes in the editor.

## Git Notes

This repository uses Git LFS for large Unreal asset types such as `*.uasset`, `*.umap`, and related binary content.
The existing `unreal 1` history remains as-is, and LFS tracking applies to future matching asset changes from `unreal 2` onward.
