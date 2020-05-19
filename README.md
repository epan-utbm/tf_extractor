# tf_extractor
A ROS package that listens to /tf and republishes the transforms between the specified two frames on the /tf_extractor/tf topic.

### Running example
```console
$ rosrun tf_extractor tf_extractor _source_frameid:=/map _target_frameid:=/base_link
```
