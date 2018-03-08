#!/usr/bin/env python


"""
Python 3 script to generate .hitagi archives used by the Hitagi game engine
Notes about the .hitagi archive format:
- the signature is 48 69 74 61 67 69 
- each file in the archive is separated by 10 bytes
"""


import struct, sys, os, glob


# read a binary file
def readFile(filename):
    fileContents = 0
    with open(filename, mode='rb') as file:
        fileContent = file.read()
    return fileContent

# create a hitagi archive given a list of byte arrays
def generateArchive(files):
    nulls = [00, 00, 00, 00, 00, 00, 00, 00, 00, 00] # used for padding
    archive = [0x48, 0x69, 0x74, 0x61, 0x67, 0x69] # archive starts with just header

    for file in files:
        archive.extend(nulls) # add buffer for files
        archive.extend(file)

        
    return archive

def main():
    print(":: Hitagi Archive Generator ::")
    archiveName = sys.argv[1]
    fileContents = []
    
    # go into the archive directory
    os.chdir(archiveName)
    for file in glob.glob("*"):
        fileContents.append(readFile(file))

    
    archive = generateArchive(fileContents)

    archiveFile = open(archiveName + ".hitagi", "wb")
    archiveBytes = bytearray(archive)
    archiveFile.write(archiveBytes)
    print("Done.")
    
if __name__ == "__main__":
    main()
