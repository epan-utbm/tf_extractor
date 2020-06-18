# tf_extractor

[![Build Status](https://travis-ci.org/epan-utbm/tf_extractor.svg?branch=melodic)](https://travis-ci.org/epan-utbm/tf_extractor) [![Codacy Badge](https://app.codacy.com/project/badge/Grade/3304a28dffab47cfb1d0076717b1a55b)](https://www.codacy.com/gh/epan-utbm/tf_extractor?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=epan-utbm/tf_extractor&amp;utm_campaign=Badge_Grade) [![License](https://img.shields.io/badge/License-BSD%203--Clause-gree.svg)](https://opensource.org/licenses/BSD-3-Clause)

A ROS package that listens to /tf and republishes the transforms between the specified two frames on the /tf_extractor/tf topic.

## Usage

```console
$ rosrun tf_extractor tf_extractor _source_frameid:=/map _target_frameid:=/base_link
```
