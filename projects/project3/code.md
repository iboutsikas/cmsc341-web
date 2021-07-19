---
layout: default
parent: "Project 3: B is NOT for binary"
title: 'Provided code'
nav_order: 50
---
{% assign project = site.data.project.project3 %}
{% include due_date.html project=project%}
{% if project.changelog %}
{% include changelog.html project=project %}
{% endif %}

<div class="alert alert-danger mt-5">
    More tests will be added as they become available
</div>

# {{page.title}}

You can find a zip that contains everything here:
<a href="{{ '/assets/project3.zip' | absolute_url }}" target="_blank"
rel="noopener noreferrer" download>{{ '/assets/project3.zip' | absolute_url
}}</a>. This includes the folder structure as well.

For reference, the folder structure is the following:
```
project3/
├── b-tree/
│   ├── b-tree.h
│   └── node.h
├── provided_code/
│   ├── data.h
│   ├── person.h
│   └── utils.h
├── left_degenerate_test.cpp
├── Makefile
├── right_degenerate_test.cpp
├── simple_test.cpp
└── test_bed.cpp
```

Each test contains some information on what it is testing. This should help you 
narrow down the issues you are seeing. In addition we've included a test_bed
test that is completely empty. You can use that to test specific things in your
implementation, without having to go through the rest of the tests. For
instance, you could just make nodes there and call their functions directly,
instead of having to call them through the tree.

# Individual files

Bellow you will find a list of the individual files that are included in the
zip, along with their download. This wy you can recover them if you
lost/modified one and you can download the new ones as they come out.

* <a href="{{ '/assets/project3/Makefile' | absolute_url }}" target="_blank"
  rel="noopener noreferrer" download>Makefile</a>: You can run `make` to build
  all tests, or `make test1` if you only want test1.

* <a href="{{ '/assets/project3/simple_test.cpp' | absolute_url }}"
  target="_blank" rel="noopener noreferrer" download>simple_test.cpp</a>: This
  is normal operation for your `try_add` and `try_find` functions. Should not
  present any "difficulty" to your code.

* <a href="{{ '/assets/project3/left_degenerate_test.cpp' | absolute_url }}"
  target="_blank" rel="noopener noreferrer"
  download>left_degenerate_test.cpp</a>: The keys are inserted in a strictly
  descending order. This would create a list if there was no balancing.

* <a href="{{ '/assets/project3/right_degenerate_test.cpp' | absolute_url }}"
  target="_blank" rel="noopener noreferrer"
  download>right_degenerate_test.cpp</a>: Same as above, but the keys are in
  strictly ascending order.

* <a href="{{ '/assets/project3/test_bed.cpp' | absolute_url }}" target="_blank"
  rel="noopener noreferrer" download>test_bed.cpp</a>: Empty test for your use.
  You can `#include` anything in the `b-tree` and `provided_code` directories on
  top of whatever is in the standard C++ library.

* <a href="{{ '/assets/project3/provided_code/data.h' | absolute_url }}"
  target="_blank" rel="noopener noreferrer" download>provided_code/data.h</a>:
  Just provides some data for the tests to use.

* <a href="{{ '/assets/project3/provided_code/person.h' | absolute_url }}"
  target="_blank" rel="noopener noreferrer" download>provided_code/person.h</a>:
  Definition of `struct Person`.

* <a href="{{ '/assets/project3/provided_code/utils.h' | absolute_url }}"
  target="_blank" rel="noopener noreferrer" download>provided_code/utils.h</a>:
  Helpers that the tests use.

* <a href="{{ '/assets/project3/b-tree/b-tree.h' | absolute_url }}"
  target="_blank" rel="noopener noreferrer" download>b-tree/b-tree.h</a>:
  Empty template for your B-Tree. Only contains the required functions

* <a href="{{ '/assets/project3/b-tree/node.h' | absolute_url }}"
  target="_blank" rel="noopener noreferrer" download>b-tree/node.h</a>:
  Empty implementation for your Node class. You can use the suggestions
  [here](./designing_nodes.md), or come up with your own!