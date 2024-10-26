#!/usr/bin/env python3

"""
install_test_part.py [part_name1.obj] [part_name2.obj] ... [part_nameN.obj]
This script assumes you have the .obj of the part.

This script installs test parts to make them usable for simulation, and grasping.
This script assumes test parts are stored in the 'src/robotic_depowdering/test_parts' folder 
- before running this script, download your .obj to that folder.
"""
from obj2stl import obj2stl
import argparse
import subprocess
import shutil

TEST_PART_DIR = "src/robotic_depowdering/test_parts/"

parser = argparse.ArgumentParser()
parser.add_argument('part_names', help='Names of parts to convert, including .obj extension', type=str, nargs="*")
args = parser.parse_args()
parts = args.part_names

for part in parts:
    # Convert from obj to stl
    stl_file_name = TEST_PART_DIR + part[:-4] + ".stl"
    shutil.move(part, TEST_PART_DIR+part)
    obj2stl.convert(input=TEST_PART_DIR+part, output=stl_file_name)

    # Create stl binary
    result = subprocess.run(["python3", "-m", "stlconverter", stl_file_name, "STLB"])
    if result.returncode != 0:
        print(f"Failed to convert part {part} to stl binary")
        continue

    result = subprocess.run(["mv", stl_file_name[:-4]+"-converted-binary.stl", TEST_PART_DIR+part+".bin.stl"])
    if result.returncode != 0:
        print(f"Failed to move part {part} to stl binary")
        continue

result = subprocess.run(["colcon", "build", "--symlink-install", "--packages-select", "robotic_depowdering"])
if result.returncode != 0:
    print(f"Failed to re-run colcon install to install updated part files")
