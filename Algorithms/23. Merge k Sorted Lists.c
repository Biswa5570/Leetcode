typedef struct {
    int val;
    int idx;
    struct ListNode* node;
} HeapNode;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(HeapNode* heap, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent].val <= heap[i].val) break;
        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

void heapifyDown(HeapNode* heap, int size, int i) {
    while (1) {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < size && heap[left].val < heap[smallest].val)
            smallest = left;
        if (right < size && heap[right].val < heap[smallest].val)
            smallest = right;

        if (smallest == i) break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

void push(HeapNode* heap, int* size, HeapNode node) {
    heap[*size] = node;
    heapifyUp(heap, *size);
    (*size)++;
}

HeapNode pop(HeapNode* heap, int* size) {
    HeapNode top = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return top;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    HeapNode* heap = (HeapNode*)malloc(listsSize * sizeof(HeapNode));
    int heapSize = 0;

    for (int i = 0; i < listsSize; i++) {
        if (lists[i]) {
            HeapNode node = {lists[i]->val, i, lists[i]};
            push(heap, &heapSize, node);
        }
    }

    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* cur = &dummy;

    while (heapSize > 0) {
        HeapNode top = pop(heap, &heapSize);

        cur->next = top.node;
        cur = cur->next;

        if (top.node->next) {
            HeapNode newNode = {top.node->next->val, top.idx, top.node->next};
            push(heap, &heapSize, newNode);
        }
    }

    free(heap);
    return dummy.next;
}
