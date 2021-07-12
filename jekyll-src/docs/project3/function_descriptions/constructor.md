---
layout: default
parent: "Function Descriptions"
grand_parent: "Project 3: B is NOT for binary"
title: 'BTree::BTree'
nav_order: 1
---
{% assign project = site.data.project.project3 %}
{% include due_date.html project=project%}
{% if project.changelog %}
{% include changelog.html project=project %}
{% endif %}

# BTree::BTree
```c++
BTree::BTree(int m, int l)
```
## Description
<p>
    Creates a new BTree, the given arguments are m and l from the lectures.
    <b>You must not modify the signature.</b> You can however add more stuff
    (i.e. the root) in the initializer list , or more logic in the body of the
    constructor.
</p>

<p>
    If you add more in the initializer list, it must be in the order they are
    declared as members. We first declared <code>m_Degree</code> and then
    <code>m_LeafSize</code> so we put them in that order in the list!
</p>

## Parameters
* **m**: The degree of the tree. Each node in the tree will have up to m
children and m-1 keys
* **l**: How many data items a data leaf can hold.