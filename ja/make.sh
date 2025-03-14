#!/bin/bash

rm -rf ../docs/*
mkdir ./_static
sphinx-build -b html . ../docs
touch ../docs/.nojekyll
