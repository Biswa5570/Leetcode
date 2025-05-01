WITH ProductPairs AS (
  SELECT
    P1.product_id AS product1_id,
    P2.product_id AS product2_id,
    P1.category AS product1_category,
    P2.category AS product2_category
  FROM
    ProductInfo P1,
    ProductInfo P2
  WHERE
    P1.product_id < P2.product_id
)
SELECT
  P.product1_id AS product1_id,
  P.product2_id AS product2_id,
  P.product1_category AS product1_category,
  P.product2_category AS product2_category,
  COUNT(DISTINCT(PP1.user_id)) AS customer_count
FROM
  ProductPairs P,
  ProductPurchases PP1,
  ProductPurchases PP2
WHERE
  P.product1_id = PP1.product_id AND
  PP1.quantity > 0 AND
  P.product2_id = PP2.product_id AND
  PP2.quantity > 0 AND
  PP1.user_id = PP2.user_id
GROUP BY
  P.product1_id,
  P.product2_id
  HAVING
    customer_count > 2
ORDER BY
  customer_count DESC,
  product1_id ASC,
  product2_id ASC;
