#!/usr/bin/env python3
#
# MindForger thinking notebook
#
# Copyright (C) 2016-2024 Martin Dvorak <martin.dvorak@mindforger.com>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.

import glob
import os
import shutil
from typing import List
from typing import Tuple


def gather_documentation_file_paths(doc_mf_repo_path) -> Tuple[List, List, str]:
    memory_path: str = os.path.join(doc_mf_repo_path, "memory")
    if not os.path.isdir(memory_path):
        raise ValueError(
            f"mindforger-documentation path is not MindForger repository - memory path"
            f"is invalid: {memory_path}"
        )

    md_paths = glob.glob(f"{memory_path}/*.md")
    png_paths = glob.glob(f"{memory_path}/*.png")
    jpg_paths = glob.glob(f"{memory_path}/*.jpg")

    image_paths: list = png_paths + jpg_paths

    return md_paths, image_paths, memory_path


def md_to_wiki_file(md_file_path: str, wiki_file_path: str):
    print(f"  {md_file_path} -> {wiki_file_path}")

    is_blacklisted: bool = False

    blocked_list: list = [
        "_Sidebar.md",
    ]
    for b in blocked_list:
        if b in md_file_path:
            is_blacklisted = True

    with open(md_file_path, "r") as md_in:
        data = md_in.read().splitlines(True)

    for i, _ in enumerate(data):
        if data[i]:
            # replace all FILE.md links to FILE (.md is used for source refs in Wiki)
            if ".md)" in data[i]:
                data[i] = data[i].replace(".md)", ")")
            # replace all FILE.md#l links to FILE (.md is used for source refs in Wiki)
            elif ".md#" in data[i] and "http" not in data[i]:
                data[i] = data[i].replace(".md#", "#")
            # strip MindForger section metadata
            elif (
                data[i].startswith("#")
                and "<!-- Metadata:" in data[i]
                and "-->" in data[i]
            ):
                data[i] = data[i][0 : data[i].index(" <!-- Metadata:")] + "\n"

    with open(wiki_file_path, "w") as wiki_out:
        wiki_out.writelines(data[1:] if not is_blacklisted else data)
    print("    CONVERT" if not is_blacklisted else "    COPY")

FILE_PATCH_FOOTER = "_Footer.md"

def doc_to_wiki(doc_mf_repo_path: str, wiki_repo_path: str):
    if not os.path.isdir(doc_mf_repo_path):
        raise ValueError(
            f"Invalid path to private mindforger-documentation GitHub repository: "
            f"'{doc_mf_repo_path}'"
        )
    if not os.path.isdir(wiki_repo_path):
        raise ValueError(
            f"Invalid path to mindforger.wiki GitHub repository: '{wiki_repo_path}'"
        )

    (
        md_paths_to_convert,
        image_paths,
        doc_mf_repo_memory_path,
    ) = gather_documentation_file_paths(doc_mf_repo_path)

    paths_to_copy: list = image_paths.copy()
    paths_to_patch: list = []

    print(f"Converting {len(md_paths_to_convert)} files:")
    for md_path in md_paths_to_convert:
        wiki_file_path = md_path.replace(doc_mf_repo_memory_path, wiki_repo_path)

        # files to patch
        if FILE_PATCH_FOOTER in wiki_file_path:
            paths_to_patch.append(wiki_file_path)

        md_to_wiki_file(
            md_file_path=md_path,
            wiki_file_path=wiki_file_path,
        )

    print(f"Patching {len(paths_to_patch)} files:")
    for p in paths_to_patch:
        print(f"  {p}")
        if FILE_PATCH_FOOTER in p:
            with open(p, "r") as file:
                filedata = file.read()
                filedata = filedata.replace(
                    "master/CREDITS",
                    "master/CREDITS.md",
                )
            with open(p, "w") as file:
                file.write(filedata)

    print(f"Copying {len(paths_to_copy)} files:")
    for p in paths_to_copy:
        print(f"  {p}")
        shutil.copy(
            src=p,
            dst=p.replace(doc_mf_repo_memory_path, wiki_repo_path),
        )


if __name__ == "__main__":
    print("Converting mindforger-documentation to mindforger.wiki:")
    home_path = os.path.expanduser("~")
    _doc_mf_repo_path = os.path.join(
        home_path,
        "p",
        "mindforger",
        "git",
        "mindforger-documentation",
    )
    _wiki_repo_path = os.path.join(
        home_path,
        "p",
        "mindforger",
        "git",
        "mindforger.wiki",
    )
    print(f"  from: {_doc_mf_repo_path}")
    print(f"  to  : {_wiki_repo_path}")

    doc_to_wiki(
        doc_mf_repo_path=_doc_mf_repo_path,
        wiki_repo_path=_wiki_repo_path,
    )

# eof
