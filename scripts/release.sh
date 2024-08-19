#!/bin/bash

mkdir -p release

# zip bin/windows as windows-release.zip under release/
zip -r ./release/windows-release.zip ./bin/Windows/*
zip -r ./release/linux-release.zip ./bin/Linux/*