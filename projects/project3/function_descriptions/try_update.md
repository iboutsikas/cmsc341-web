---
layout: default
parent: "Function Descriptions"
grand_parent: "Project 3: B is NOT for binary"
title: 'BTree::try_update'
nav_order: 4
---
{% assign project = site.data.project.project3 %}
{% include due_date.html project=project%}
{% if project.changelog %}
{% include changelog.html project=project %}
{% endif %}

# BTree::try_update
```c++
bool BTree::try_update(const TKey& key, const TIndex& inIndex) const
```
## Description
<p>
    Attempts to update the element in the tree. If the key was not found, the
    function does not modify the tree **in any way**. If the element is found, you
    can assume that the assignment operator for TIndex will be enough to do the
    update for you.
</p>

<p>
    You can assume that the key implements all of the standard
    operators (i.e. <code> &gt;, &lt;, &geq;, &leq;, == </code>). You can also
    assume that there is a <code>TKey == TIndex</code> operator.
</p>

## Parameters
* **key**: The key for this element
* **inIndex**: The new values for the element

## Return
If the element was found the function should return true. If the
element does not exist, the function should return false. In any other case the
function should return false.