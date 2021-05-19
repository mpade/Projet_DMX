-- phpMyAdmin SQL Dump
-- version 4.9.2
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3306
-- Généré le :  ven. 07 mai 2021 à 20:49
-- Version du serveur :  10.4.10-MariaDB
-- Version de PHP :  7.3.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `projet_dmx`
--

-- --------------------------------------------------------

--
-- Structure de la table `adressequipement`
--

DROP TABLE IF EXISTS `adressequipement`;
CREATE TABLE IF NOT EXISTS `adressequipement` (
  `Id_AdressEquipement` int(11) NOT NULL AUTO_INCREMENT,
  `Adresse` int(11) NOT NULL,
  `Id_Equipement` int(11) NOT NULL,
  PRIMARY KEY (`Id_AdressEquipement`),
  KEY `Id_Equipement` (`Id_Equipement`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `adressequipement`
--

INSERT INTO `adressequipement` (`Id_AdressEquipement`, `Adresse`, `Id_Equipement`) VALUES
(1, 1, 1),
(2, 4, 2);

-- --------------------------------------------------------

--
-- Structure de la table `equipement`
--

DROP TABLE IF EXISTS `equipement`;
CREATE TABLE IF NOT EXISTS `equipement` (
  `Id_Equipement` int(11) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) NOT NULL,
  `Id_Property` int(11) NOT NULL,
  `Nb_voie` int(11) NOT NULL,
  PRIMARY KEY (`Id_Equipement`),
  KEY `Id_Property` (`Id_Property`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `equipement`
--

INSERT INTO `equipement` (`Id_Equipement`, `Name`, `Id_Property`, `Nb_voie`) VALUES
(1, 'Equipement numero one', 1, 3),
(2, 'Equipement nomero two', 2, 4);

-- --------------------------------------------------------

--
-- Structure de la table `manager`
--

DROP TABLE IF EXISTS `manager`;
CREATE TABLE IF NOT EXISTS `manager` (
  `Id_Manager` int(11) NOT NULL AUTO_INCREMENT,
  `Programme` int(11) NOT NULL,
  `Scene` int(11) NOT NULL,
  `Id_Scene` int(11) NOT NULL,
  `Id_Programme` int(11) NOT NULL,
  PRIMARY KEY (`Id_Manager`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `programme`
--

DROP TABLE IF EXISTS `programme`;
CREATE TABLE IF NOT EXISTS `programme` (
  `Id_Programme` int(11) NOT NULL AUTO_INCREMENT,
  `Nom` varchar(255) NOT NULL,
  PRIMARY KEY (`Id_Programme`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `property`
--

DROP TABLE IF EXISTS `property`;
CREATE TABLE IF NOT EXISTS `property` (
  `Id_Property` int(11) NOT NULL AUTO_INCREMENT,
  `Order` int(11) NOT NULL,
  `Description` varchar(255) NOT NULL,
  `nameproperty` varchar(25) NOT NULL,
  PRIMARY KEY (`Id_Property`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `property`
--

INSERT INTO `property` (`Id_Property`, `Order`, `Description`, `nameproperty`) VALUES
(1, 1, 'lampe rgb', 'Equipoement 1'),
(2, 2, 'lampe wrgb', 'Equipement 2');

-- --------------------------------------------------------

--
-- Structure de la table `scene`
--

DROP TABLE IF EXISTS `scene`;
CREATE TABLE IF NOT EXISTS `scene` (
  `Id_Scene` int(11) NOT NULL AUTO_INCREMENT,
  `Nom` varchar(255) NOT NULL,
  PRIMARY KEY (`Id_Scene`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `sceneprogramme`
--

DROP TABLE IF EXISTS `sceneprogramme`;
CREATE TABLE IF NOT EXISTS `sceneprogramme` (
  `Id_SceneProgramme` int(11) NOT NULL AUTO_INCREMENT,
  `Id_Scene` int(11) NOT NULL,
  `Id_Programme` int(11) NOT NULL,
  PRIMARY KEY (`Id_SceneProgramme`),
  KEY `Id_Programme` (`Id_Programme`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `sequence`
--

DROP TABLE IF EXISTS `sequence`;
CREATE TABLE IF NOT EXISTS `sequence` (
  `Id_Sequence` int(11) NOT NULL AUTO_INCREMENT,
  `Duree` int(11) NOT NULL,
  `name` varchar(25) NOT NULL,
  PRIMARY KEY (`Id_Sequence`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `sequencescene`
--

DROP TABLE IF EXISTS `sequencescene`;
CREATE TABLE IF NOT EXISTS `sequencescene` (
  `Id_SequenceScene` int(11) NOT NULL AUTO_INCREMENT,
  `Id_Sequence` int(11) NOT NULL,
  `Id_Scene` int(11) NOT NULL,
  `Order` int(11) NOT NULL,
  PRIMARY KEY (`Id_SequenceScene`),
  KEY `Id_Scene` (`Id_Scene`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `sequenceusedequipement`
--

DROP TABLE IF EXISTS `sequenceusedequipement`;
CREATE TABLE IF NOT EXISTS `sequenceusedequipement` (
  `Id_SequenceUsedEquipement` int(11) NOT NULL AUTO_INCREMENT,
  `Valeur` int(11) NOT NULL,
  `Id_AdressEquipement` int(11) NOT NULL,
  `Id_Sequence` int(11) NOT NULL,
  `adress` int(11) NOT NULL,
  PRIMARY KEY (`Id_SequenceUsedEquipement`),
  KEY `Id_AdressEquipement` (`Id_AdressEquipement`),
  KEY `Id_Sequence` (`Id_Sequence`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `utilisateur`
--

DROP TABLE IF EXISTS `utilisateur`;
CREATE TABLE IF NOT EXISTS `utilisateur` (
  `Id_Utilisateur` int(11) NOT NULL AUTO_INCREMENT,
  `Nom` varchar(255) NOT NULL,
  `Prenom` varchar(255) NOT NULL,
  `Email` varchar(255) NOT NULL,
  `MotDePasse` varchar(255) NOT NULL,
  `Grade` int(11) NOT NULL,
  PRIMARY KEY (`Id_Utilisateur`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `utilisateur`
--

INSERT INTO `utilisateur` (`Id_Utilisateur`, `Nom`, `Prenom`, `Email`, `MotDePasse`, `Grade`) VALUES
(1, 'marco', 'marco', 'mpade@la-providence.net', 'Pade', 0);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
