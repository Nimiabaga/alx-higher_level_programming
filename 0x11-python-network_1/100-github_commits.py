#!/usr/bin/python3
"""
Python script that lists 10 commits (from the most recent to oldest) of a repository
by a specific user using the GitHub API.
"""


import sys
import requests


if __name__ == "__main__":
    address = 'https://api.github.com/repos/{}/{}/commits'
    ans = requests.get(address.format(sys.argv[2], sys.argv[1]))
    info = ans.json()

    for commit in info[:10]:
        sha = commit['sha']
        can = commit['commit']['author']['name']
        print("{}: {}".format(sha, can))
