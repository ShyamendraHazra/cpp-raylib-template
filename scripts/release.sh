#!/bin/bash

source ./scripts/globals.sh

mkdir -p release

# zip bin/windows as windows-release.zip under release/
zip -r "$PROJECT_ROOT"/release/windows-release.zip ./bin/Windows/*
zip -r "$PROJECT_ROOT"/release/linux-release.zip ./bin/Linux/*