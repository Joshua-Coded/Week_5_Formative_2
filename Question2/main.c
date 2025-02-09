#include <stdio.h>
#include "include/auction.h"

int main() {
    MaxHeap auctionHeap;
    initHeap(&auctionHeap);

    // Initial bids
    printf("Initial bids being placed...\n");
    updateBid(&auctionHeap, "Table", 150.0);
    updateBid(&auctionHeap, "Fridge", 800.0);
    updateBid(&auctionHeap, "Kettle", 50.0);
    updateBid(&auctionHeap, "Sofa Set", 1200.0);
    updateBid(&auctionHeap, "Office Chair", 300.0);
    updateBid(&auctionHeap, "TV", 1000.0);

    printf("\nInitial auction status:");
    printHeap(&auctionHeap);

    // Simulate new bids
    printf("\nNew bids coming in...\n");
    updateBid(&auctionHeap, "Kettle", 75.0);  // Higher bid for kettle
    updateBid(&auctionHeap, "TV", 1500.0);    // Higher bid for TV
    
    printf("\nUpdated auction status:");
    printHeap(&auctionHeap);

    // Extract items in priority order (highest bid first)
    printf("\nExtracting items in order of highest bid:\n");
    printf("----------------------------------------\n");
    while (auctionHeap.size > 0) {
        AuctionItem highest = extractMax(&auctionHeap);
        printf("%s: $%.2f\n", highest.itemName, highest.currentBid);
    }

    return 0;
}
