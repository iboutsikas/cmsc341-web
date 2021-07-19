---
layout: default
parent: "Project 3: B is NOT for binary"
title: 'operator TKey()'
nav_order: 8
---

{% assign project = site.data.project.project3 %}
{% include due_date.html project=project%}
{% if project.changelog %}
{% include changelog.html project=project %}
{% endif %}

# Project 3: {{page.title}}

In this project, you will need some way to convert from a `TIndex` to a `TKey`.
You can assume that the operator always exists in your code, as we will be
providing it where necessary, and the primitive data types in C++ already do it
(for our purposes at least).

Specifically, you can always assume that the following is a valid operation:

```c++
TIndex some_index_that_I_got_somehow;
TKey the_key_I_want = some_index_that_I_got_somehow;
```