#!/bin/bash
# This script takes a URL as input, sends a request to that URLsize of the body of the response.

curl -sI "$1" | grep -i Content-Length | awk '{print $2}'
