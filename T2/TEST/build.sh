#!/bin/bash

emcc calculadora.cpp -o calculadora.js \
  -s MODULARIZE=1 \
  -s 'EXPORT_NAME="Module"' \
  --bind
