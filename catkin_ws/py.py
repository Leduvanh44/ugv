#!/usr/bin/env python

import rospy
from urdf_parser_py.urdf import URDF
import pydot

def urdf_to_dot(robot):
    graph = pydot.Dot(graph_type='digraph')
    for joint in robot.joints:
        graph.add_edge(pydot.Edge(joint.parent, joint.child, label=joint.name))
    return graph

if __name__ == '__main__':
    import sys
    if len(sys.argv) < 2:
        print("Usage: urdf_to_dot.py <urdf_file>")
        sys.exit(1)
    
    urdf_file = sys.argv[1]
    robot = URDF.from_xml_file(urdf_file)
    graph = urdf_to_dot(robot)
    output_file = urdf_file.split('.')[0] + '.dot'
    graph.write(output_file, format='raw')
    print(f"DOT file saved to {output_file}")
