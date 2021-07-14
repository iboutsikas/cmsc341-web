
#pragma once

#include "node.h"

template <typename TKey, typename TIndex>
class BTree;


template <typename TKey, typename TIndex>
class BTree {
    int m_Degree;
    int m_LeafSize;
    Node<TKey, TIndex>* m_Root;
    
public:
    BTree(int m, int l);

    bool try_add(const TKey& key, const TIndex& inIndex);

    bool try_find(const TKey& key, TIndex& outIndex) const;

    bool try_update(const TKey& key, const TIndex& inIndex) const;

    bool try_delete(const TKey& key);
};


template <typename TKey, typename TIndex>
BTree<TKey, TIndex>::BTree(int m, int l)
    : m_Degree(m)
    , m_LeafSize(l)
    , m_Root(nullptr)
{

}

template <typename TKey, typename TIndex>
bool BTree<TKey, TIndex>::try_add(const TKey& key, const TIndex& inIndex)
{
    return false;
}

template <typename TKey, typename TIndex>
bool BTree<TKey, TIndex>::try_find(const TKey& key, TIndex& outIndex) const
{
    return false;
}

template <typename TKey, typename TIndex>
bool BTree<TKey, TIndex>::try_update(const TKey& key, const TIndex& inIndex) const
{
    return false;
}

template <typename TKey, typename TIndex>
bool try_delete(const TKey& key)
{
    return false;
}