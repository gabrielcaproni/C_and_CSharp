use banco_cadastro;
--
-- Table structure for table `generos`
--

DROP TABLE IF EXISTS `generos`;

CREATE TABLE `generos` (
  `idgenero` int NOT NULL AUTO_INCREMENT,
  `genero` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`idgenero`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4;

--
-- Table structure for table `bandas`
--

DROP TABLE IF EXISTS `bandas`;
CREATE TABLE `bandas` (
  `idbandas` int NOT NULL AUTO_INCREMENT,
  `nome` varchar(45) DEFAULT NULL,
  `integrantes` int DEFAULT NULL,
  `ranking` int DEFAULT NULL,
  `genero` int DEFAULT NULL,
  PRIMARY KEY (`idbandas`),
  KEY `genero_idx` (`genero`),
  CONSTRAINT `genero` FOREIGN KEY (`genero`) REFERENCES `generos` (`idgenero`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `generos`
--

INSERT INTO `generos` VALUES (1,'Rock'),(2,'Metal'),(3,'Pagode');
